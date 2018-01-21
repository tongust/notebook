# Download and set up site
## Download
```shell
wget https://cygwin.com/setup-x86.exe
```
Run setup-x86.exe any time you want to update or install a Cygwin package.
Better to move setup-x86.exe where you can find easily.
Such: *C:\cygwin64*
## Set update site
http://mirrors.163.com/cygwin/
http://mirrors.ustc.edu.cn/cygwin/

# Set up apt-cyg
## Use setup-x86.exe to install wget etc.

[apt-cyg setup](https://stackoverflow.com/questions/9751845/apt-get-for-cygwin)
```shell
cd C:\cygwin64
setup-x86_64 -q -P wget,tar,qawk,bzip2,subversion,vim
```
## Open cygwin
```
wget rawgit.com/transcode-open/apt-cyg/master/apt-cyg
install apt-cyg /bin
```
Until now, you can use it as *apt-get* in Ubuntu!
```shell
apt-cyg install wget
apt-cyg install curl
apt-cyg install rlwrap
apt-cyg install tar
apt-cyg install gcc-core
apt-cyg install libpng15
apt-cyg install libpng-devel
apt-cyg install openssh
apt-cyg install xorg-server
apt-cyg install xinit
apt-cyg install xorg-docs
apt-cyg install xterm
apt-cyg install make
apt-cyg install gdb
apt-cyg install vim
```
