
Debian
====================
This directory contains files used to package australiacashd/australiacash-qt
for Debian-based Linux systems. If you compile australiacashd/australiacash-qt yourself, there are some useful files here.

## australiacash: URI support ##


australiacash-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install australiacash-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your australiacash-qt binary to `/usr/bin`
and the `../../share/pixmaps/australiacash128.png` to `/usr/share/pixmaps`

australiacash-qt.protocol (KDE)

