
Debian
====================
This directory contains files used to package auscashd/auscash-qt
for Debian-based Linux systems. If you compile auscashd/auscash-qt yourself, there are some useful files here.

## auscash: URI support ##


auscash-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install auscash-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your auscash-qt binary to `/usr/bin`
and the `../../share/pixmaps/auscash128.png` to `/usr/share/pixmaps`

auscash-qt.protocol (KDE)

