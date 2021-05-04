build mac os

# Xcode And other tools
1. install Xcode
2. install Xcode Comnnad Line Tools:`sudo xcode-select --install`
3. install MacPorts:`https://www.macports.org/install.php`
4. updatesoft:`sudo port selfupdate`
5. install boost db48 miniunpc :`sudo port install boost db48 miniupnpc`


# QT SDK Build
## build qt4.8.7 sdk from source
1. download source from http://download.qt-project.org/archive/qt/4.8/4.8.7/
2. unzip qt-everywhere-opensource-src-4.8.7.tar.gz
3. remove folder demos,doc,examples, those projects not build
4. terminal execute : `./configure -release -static -fast`