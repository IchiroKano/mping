# mping
A mping targets multiple IP addresses


#1. wget https://github.com/IchiroKano/mping/releases/download/v1.1/mping.zip
#2. unzip mping.zip
#3. ./mping \<IP address1\> \<IP address2\> ...

Example -------------------------------------------------

```
$ ./mping 10.132.7.25 10.132.7.44 10.132.7.60 10.132.7.52
\-----------------------------------------------
A mping targets 4 IP address:
\-----------------------------------------------
 Fri Mar 23 00:26:37 2018
     10.132.7.25     10.132.7.44     10.132.7.60     10.132.7.52
               0               0               0               0 <- NG out of 0
        0.861 ms        0.916 ms      *** NG ***         1.12 ms
        0.592 ms        0.505 ms      *** NG ***        0.760 ms
        0.599 ms        0.477 ms      *** NG ***        0.481 ms
        0.559 ms        0.404 ms      *** NG ***        0.531 ms
        0.518 ms        0.404 ms      *** NG ***        0.513 ms
        0.588 ms        0.364 ms      *** NG ***        0.459 ms
        0.622 ms        0.492 ms      *** NG ***        0.495 ms
        0.662 ms        0.431 ms      *** NG ***        0.572 ms
        0.583 ms        0.593 ms      *** NG ***        0.654 ms
        0.580 ms        0.544 ms      *** NG ***        0.512 ms
 Fri Mar 23 00:27:18 2018
     10.132.7.25     10.132.7.44     10.132.7.60     10.132.7.52
               0               0              10               0 <- NG out of 10
        0.455 ms        0.492 ms      *** NG ***        0.436 ms
```
