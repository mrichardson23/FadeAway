<?php
	/*
		Twitter searcher for Fade Away project. This version of the
		server code sends the entire tweet.
		
		requires twittersearch, available at: http://greenservr.com/projects/twittersearch/TwitterSearch.phps
	*/
	
	include 'twittersearch.phps';
		$search->user_agent = 'mrichardson23@gmail.com';
		$search = new TwitterSearch('%22fade%20away%22');
		$results = $search->results();
		$tweet = ($results[rand(0,count($results))]->text);	//pick a random tweet from result set.
		echo $tweet;
		echo chr(23);
?>