Group 5
Members: Jonathan Ma (dm269), Hong Niu (hn36), Jason Wang (jsw50)
Server: http://310test.cs.duke.edu:9085

All the files used in this assignment to smash the stack and hack into the server
are included in the folder.

REVIEW OF OUR ATTACK

In order to complete the project, we found the vulnerability in the server code,
we constructed an attack string to attack the vulnerability with a buffer overflow,
and then used the shellcode in the attack string to open a new port to access so we
could change the server files.

We scanned the server code and found a section that we believed would be a
vulnerability. This section of code was in the check_filename_length() function
that exists in the handle() function.

At line 150, where the check_filename_length() function begins, we see that the
length of the string is inputted as a byte, which means that as long as the
last byte of the length of the string is less than 100, then we will be able to
pass the if statement. Therefore, we can use this vulnerability to pass in
a huge attack string that can cause a buffer overflow.

So, we create an attack string that looks like this:

[Repeated Return Address][No-op section][Shellcode]

We repeat the return addresses to better ensure that the return address we want
will replace the original return address in the stack. However, we did have to
find the correct return address and in order to do this, we moved from the highest
stack address of 0xBFFFFFFF and moved downwards until we found an address that works.
We chose to spawn the shell on port 5000.

In order to create this attack string, we wrote a C program that would create this
string into a .dat file that we would then call in our command:

cat shellfile.dat | nc 310test.cs.duke.edu 9085

Once we spawn the shell, we access it using the nc command in another terminal
and then we start messing with the files on the server. We edited the index.html
file and we also created a new file called happy.html.

Before we tried our attack on the remote server, we first made sure that it worked
on a locally running server.

REVIEW OF THE PROJECT

We thought the project was extremely helpful in teaching us how servers are exploited
and what kind of conditions must exist in order for a server to be exploited. This
was also a good introduction to shell programming and networking, although we think
a bit more information regarding both topics with respect to this assignment would
have been a bit helpful. We also think that perhaps giving us an introduction to
actually writing the shellcode would've been very cool, since all we really had to
do was reuse shellcode that was given to us. We also appreciated that this project
gave us a better understanding of how GDB works, which will be helpful in the future.
Overall, it was pretty awesome once we finally got everything working and got to hack
into the remote server. 
