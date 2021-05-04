平台：windows7

第一步:安装变编译环境QT和MINGW,msys

1、msys是一个在windows平台模拟shell的程序。
   
访问http://sourceforge.net/projects/mingw/files/Installer/mingw-get-setup.exe/download
下载安装程序之后，通过安装管理程序，按安装以下内容：
From MinGW installation manager -> All packages -> MSYS
选中以下安装包

msys-base-bin
msys-autoconf-bin
msys-automake-bin
msys-libtool-bin
点 apply changes开始安装。他会自动下载安装好。
需要注意的是，确保不要安装msys-gcc和msys-w32api ，因为这两个包和我们的编译系统发生冲突。
很多人出现一些莫名其妙的问题，就是因为这两个包。
2、安装 MinGW-builds
 访问
http://sourceforge.net/projects/mingw-w64/files/Toolchains targetting Win32/Personal Builds/mingw-builds/4.8.2/threads-posix/dwarf/i686-4.8.2-release-posix-dwarf-rt_v3-rev3.7z/download
下载并解压缩 i686-4.8.2-release-posix-dwarf-rt_v3-rev3.7z 到C盘根目录  C:\
注意我的目录结构。你尽量和我一样。

3、设置PATH环境变量，将C:\mingw32\bin;添加到第一个。
4、在命令行模式下输入 gc -v 会得到以下内容
c:\gcc -v
Using built-in specs.
COLLECT_GCC=c:\mingw32\bin\gcc.exe
COLLECT_LTO_WRAPPER=c:/mingw32/bin/../libexec/gcc/i686-w64-mingw32/4.8.2/lto-wrapper.exe
Target: i686-w64-mingw32
Configured with: ../../../src/gcc-4.8.2/configure --host=i686-w64-mingw32 --build=i686-w64-mingw32 --target=i686-w64-mingw32 --prefix=/mingw32 --with-sysroot=/c/mingw482/i686-482-posix-dwarf-rt_v3-rev3/mingw32 --with-gxx-include-dir=/mingw32/i686-w64-mingw32/include/c++ --enable-shared --enable-static --disable-multilib --enable-languages=ada,c,c++,fortran,objc,obj-c++,lto --enable-libstdcxx-time=yes --enable-threads=posix --enable-libgomp --enable-libatomic --enable-lto --enable-graphite --enable-checking=release --enable-fully-dynamic-string --enable-version-specific-runtime-libs --disable-sjlj-exceptions --with-dwarf2 --disable-isl-version-check --disable-cloog-version-check --disable-libstdcxx-pch --disable-libstdcxx-debug --enable-bootstrap --disable-rpath --disable-win32-registry --disable-nls --disable-werror --disable-symvers --with-gnu-as --with-gnu-ld --with-arch=i686 --with-tune=generic --with-libiconv --with-system-zlib --with-gmp=/c/mingw482/prerequisites/i686-w64-mingw32-static --with-mpfr=/c/mingw482/prerequisites/i686-w64-mingw32-static --with-mpc=/c/mingw482/prerequisites/i686-w64-mingw32-static --with-isl=/c/mingw482/prerequisites/i686-w64-mingw32-static --with-cloog=/c/mingw482/prerequisites/i686-w64-mingw32-static --enable-cloog-backend=isl --with-pkgversion='i686-posix-dwarf-rev3, Built by MinGW-W64 project' --with-bugurl=http://sourceforge.net/projects/mingw-w64 CFLAGS='-O2 -pipe -I/c/mingw482/i686-482-posix-dwarf-rt_v3-rev3/mingw32/opt/include -I/c/mingw482/prerequisites/i686-zlib-static/include -I/c/mingw482/prerequisites/i686-w64-mingw32-static/include' CXXFLAGS='-O2 -pipe -I/c/mingw482/i686-482-posix-dwarf-rt_v3-rev3/mingw32/opt/include -I/c/mingw482/prerequisites/i686-zlib-static/include -I/c/mingw482/prerequisites/i686-w64-mingw32-static/include' CPPFLAGS= LDFLAGS='-pipe -L/c/mingw482/i686-482-posix-dwarf-rt_v3-rev3/mingw32/opt/lib -L/c/mingw482/prerequisites/i686-zlib-static/lib -L/c/mingw482/prerequisites/i686-w64-mingw32-static/lib -Wl,--large-address-aware'
Thread model: posix
gcc version 4.8.2 (i686-posix-dwarf-rev3, Built by MinGW-W64 project)
至此，你的开发环境已经搭建好了，很简单吧

第二部分：下载引用的外部库

我们把它们全部放在 C:\deps目录下
2.1 安装OpenSSL下载：http://www.openssl.org/source/openssl-1.0.1g.tar.gz
 进入启动 MinGw shell 比如目录：(C:\MinGW\msys\1.0\msys.bat)运行这个msys.bat，就会启动一个shell环境，提示符是$
输入命令
cd /c/deps/
tar xvfz openssl-1.0.1g.tar.gz
cd openssl-1.0.1g
Configure no-shared no-dso mingw
make

等待几分钟后，就把openssl编译好了。

2.2 下载Berkeley DB 访问： http://download.oracle.com/berkeley-db/db-4.8.30.NC.tar.gz
我们推荐使用  4.8版本 
同样在msys shell环境下输入以下命令
cd /c/deps/
tar xvfz db-4.8.30.NC.tar.gz
cd db-4.8.30.NC/build_unix
../dist/configure --enable-mingw --enable-cxx --disable-shared --disable-replication
make
等待编译

2.3 安装Boost，下载地址： http://sourceforge.net/projects/boost/files/boost/1.55.0/

msys命令:
cd C:\deps\boost_1_55_0\
bootstrap.bat mingw
b2 --build-type=complete --with-chrono --with-filesystem --with-program_options --with-system --with-thread toolset=gcc variant=release link=static threading=multi runtime-link=static stage


2.4 安装Miniupnpc 下载地址： http://miniupnp.free.fr/files/download.php?file=miniupnpc-1.9.tar.gz

cd C:\deps\miniupnpc
mingw32-make -f Makefile.mingw init upnpc-static

2.6 qrencode:
下载地址： http://prdownloads.sourceforge.net/libpng/libpng-1.6.10.tar.gz?download 
命令
cd /c/deps/libpng-1.6.10
configure --disable-shared
make

下载 http://fukuchi.org/works/qrencode/qrencode-3.4.3.tar.gz ode:
cd /c/deps/qrencode-3.4.3

LIBS="../libpng-1.6.10/.libs/libpng16.a ../../mingw32/i686-w64-mingw32/lib/libz.a" \
png_CFLAGS="-I../libpng-1.6.10" \
png_LIBS="-L../libpng-1.6.10/.libs" \
configure --enable-static --disable-shared --without-tools

make


2.7 安装 Qt 5 库
下载和解压缩
http://download.qt-project.org/official_releases/qt/5.2/5.2.1/submodules/qtbase-opensource-src-5.2.1.7z
http://download.qt-project.org/official_releases/qt/5.2/5.2.1/submodules/qttools-opensource-src-5.2.1.7z
在 windows命令行输入：
set INCLUDE=C:\deps\libpng-1.6.10;C:\deps\openssl-1.0.1g\include
set LIB=C:\deps\libpng-1.6.10\.libs;C:\deps\openssl-1.0.1g

cd C:\Qt\5.2.1
configure.bat -release -opensource -confirm-license -static -make libs -no-sql-sqlite -no-opengl -system-zlib -qt-pcre -no-icu -no-gif -system-libpng -no-libjpeg -no-freetype -no-angle -no-vcproj -openssl-linked -no-dbus -no-audio-backend -no-wmf-backend -no-qml-debug

mingw32-make

set PATH=%PATH%;C:\Qt\5.2.1\bin

cd C:\Qt\qttools-opensource-src-5.2.1
qmake qttools.pro
mingw32-make

3. 下载Bitcoin 0.9.1 地址： https://github.com/bitcoin/bitcoin/archive/v0.9.1.zip

在msys shell下输入以下命令行:
cp /c/deps/libpng-1.6.10/.libs/libpng16.a /c/deps/libpng-1.6.10/.libs/libpng.a


//编译qt钱包
qmake bitcoin-qt-win.pro RELEASE=1 USE_UPNP=0 USE_QRCODE=1 USE_IPV6=0 
make -f Makefile 
strip infinitecoin-qt

//静态编译 infinitecoind
cd src/ && make -f makefile.unix STATIC=1 USE_UPNP=- USE_IPV6=0 && strip infinitecoind
