<?php
	/*
		Twitter searcher for Fade Away project. This version of the
		server code breaks up the tweets so that they're transmitted
		50 characters at a time. This is so that they can be pulled into
		the Arduino without overflowing the serial buffer when it's
		hooked up via XBee Internet Gateway.
		
		requires twittersearch, available at: http://greenservr.com/projects/twittersearch/TwitterSearch.phps
	*/
	include 'twittersearch.phps';
	$myFile = "storeTweet.txt";
	if(file_exists($myFile)) {
		// If this file exists, then we have a tweet that we haven't
		// finished sending, do that now:
		$fh = fopen($myFile, 'r') or die("can't open file");
		$storeString = fread($fh, 500);
		fclose($fh);
		if (strlen($storeString) > 50) {
			// If there are still more than 50 chars, send 50 and store the remainder
			echo subStr($storeString, 50);
			$fh = fopen($myFile, 'w') or die("can't open file");
			fwrite($fh, (subStr($storeString, 50, strlen($storeString) - 50)));
			fclose($fh);
		}
		else {
			//Otherwise, just send the whole thing
			echo $storeString;
			echo chr(23); // tell ardy we're done.
			unlink($myFile); // delete file when we're done with it.
		}
	}
	else {
		// If there's no file, search twitter for a tweet
		$search->user_agent = 'mrichardson23@gmail.com';
		$search = new TwitterSearch('%22fade%20away%22');
		$results = $search->results();
		$tweet = ($results[rand(0,count($results))]->text);	//pick a random tweet from result set.
		if (strlen($tweet) > 50) {
			//Send the first fifty chars and save the rest:
			echo substr($tweet, 0, 50);
			$fh = fopen($myFile, 'w') or die("can't open file");
			fwrite($fh, (subStr($tweet, 50, strlen($tweet) - 50)));
			fclose($fh);
		}
		else {
			echo $tweet;
			echo chr(23);
		}
	}
	
?>