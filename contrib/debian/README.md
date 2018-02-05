
Debian
====================
This directory contains files used to package justpayd/justpay-qt
for Debian-based Linux systems. If you compile justpayd/justpay-qt yourself, there are some useful files here.

## justpay: URI support ##


justpay-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install justpay-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your justpayqt binary to `/usr/bin`
and the `../../share/pixmaps/justpay128.png` to `/usr/share/pixmaps`

justpay-qt.protocol (KDE)

