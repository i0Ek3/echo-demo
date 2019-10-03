# echo-demo

echo server under the Windows, easy and tiny, just a demo.

Actually this is my first time to write C++ program under the Windows, just for fun.

Purpose of this repo just to inside the Windows socket network programming, and know the differences with Linux socket network programming.

In fact, there are just some functions is not totally same as Linux, but the mind is same.

Oh, this repo implement TCP echo server and UDP echo server, have fun.

In TCP echo server, we need socket()/bind()/listen()/connect()/recv()/send() and etc., but in UDP, we just need bind()/recvfrom()/sendto().

More about socket networking programming please visit this site: [http://c.biancheng.net/view/2349.html](http://c.biancheng.net/view/2349.html).

Let we just do it!

