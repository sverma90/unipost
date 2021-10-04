# unipost

####Objectives

<ul>
 <li>Implement a multi-key sorting algorithm.</li>
 <li>Implement a C program split among multiple source files.</li>
 <li>Implement an Abstract Data Type for sorting posts on a social network.</li>
 <li>Use a C struct and arrays to collect and organize data.</li>
</ul>

<p>Implement a Universal Post Manager ADT to manage and search posts from various social networks. The Universal Post Manager (UniPost) is a collection of structs, each containing a User ID, a Network name, a date, a time, and a string of text posted to a network. The idea of UniPost is to allow a single program to manage the news feeds of multiple networks.</p>

<p>The functions that manipulate the log are declared in a file called unipost.h. The API allows a client program to:</p>
<ul>
 <li>Add log entries.</li>
 <li>Print the log to the screen.</li>
 <li>Sort all posts by date/time, hashtag within the post, User ID, or network name.</li>
 <li>Save the log to a file.</li>
 <li>Read the log entries from a file.</li>
</ul>
