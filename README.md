# Simple Sockets
This is a Simple Sever and Client I created while following this tutorial [C/C++ Sockets Tutorial](https://www.linuxhowtos.org/C_C++/socket.htm). The goals of this project were to get back into C++ and learn about sockets and designing servers.

## Compiling the Code
Build the project \
`cmake --build cmake-build-debug --target simple-socket-server` \
`cmake --build cmake-build-debug --target simple-socket-client`

move into the build directory \
`cd cmake-build-debug`

Set the executable bit on the executables \
`chmod +x simple-socket-server` \
`chmod +x simple-socket-client`

move the executables to a better location \
`mv simple-socket-* [some location]`

## Running the pre-complied versions
_**Compiled on Debian kernel version 5.16.11-76051611-generic arch x86_64**_

_Note: if you are compiling the code you can skip the first 3 steps as they are performed above_ 

Change directory to built \
`cd built`

Set the executable bit to the executables \
`chmod +x simple-socket-server` \
`chmod +x simple-socket-client`

move the executables to a better location \
`mv simple-socket-* [some location]`

Move to the directory you placed the executables in \
Run some commands \
`./simple-socket-server 5546` _Note: if you placed the executable in PATH you do not need the proceeding ./_
In a new terminal
`./simple-socket-server 127.0.0.1 5546` _Note: if you placed the executable in PATH you do not need the proceeding ./_

## Further Reading
_I have started reading the following after completing this tutorial_
- [ ] [Internetworking with TCP/IP Volume One 6th Edition](https://www.amazon.com/Internetworking-TCP-IP-One-6th/dp/013608530X/ref=pd_sbs_2/146-0905989-7407724?pd_rd_w=mzw2p&pf_rd_p=4b6b5072-e9bd-4f30-a3af-a1f5d52978ec&pf_rd_r=22N4YSEQZK3Y8ZYQCM5F&pd_rd_r=435d9b2f-a4c7-4fd6-af60-7b9c8791deaa&pd_rd_wg=c47cP&pd_rd_i=013608530X&psc=1)
- [ ] [TCP/IP Sockets in C, 2nd Edition by Michael J. Donahoo, Kenneth L. Calvert](https://www.amazon.com/TCP-IP-Sockets-Practical-Programmers/dp/0123745403)

## Future Plans for the Project
-[ ] Fork off new Processes to handle multiple connections
-[ ] Implement a fix for the zombie problem the above step will assuredly create
-[ ] Complete this project by having the server take a screenshot of the current desktop environment and pass it to the client.
