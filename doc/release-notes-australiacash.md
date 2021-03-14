Australiacash Core version 0.17.2 is now available from:

  <https://www.australiacash.org/downloads/>

This is a new minor version release, with various bugfixes
as well as updated seeds.

Please report bugs using the issue tracker at GitHub:

  <https://github.com/australiacash/australiacash-core/issues>

To receive security and update notifications, please subscribe to:

  <https://groups.google.com/forum/#!forum/australiacash-dev>

How to Upgrade
==============

If you are running an older version, shut it down. Wait until it has completely
shut down (which might take a few minutes for older versions), then run the
installer (on Windows) or just copy over `/Applications/Australiacash-Qt` (on Mac)
or `australiacashd`/`australiacash-qt` (on Linux).


Downgrading warning
-------------------

Wallets created in 0.17 and later are not compatible with versions prior to 0.17
and will not work if you try to use newly created wallets in older versions. Existing
wallets that were created with older versions are not affected by this.

Compatibility
==============

Australiacash Core is extensively tested on multiple operating systems using
the Linux kernel, macOS 10.8+, and Windows Vista and later. Windows XP is not supported.

Australiacash Core should also work on most other Unix-like systems but is not
frequently tested on them.

Notable changes
===============

------------------

### Consensus
- #14249 `696b936` Fix crash bug with duplicate inputs within a transaction (TheBlueMatt, sdaftuar)

Credits
=======

Thanks to everyone who directly contributed to this release:

- [The Bitcoin Core Developers](/doc/release-notes)
- Adrian Gallagher
- aunyks
- coblee
- cryptonexii
- gabrieldov
- jmutkawoa
- Martin Smith
- NeMO84
- ppm0
- romanornr
- shaolinfry
- spl0i7
- stedwms
- ultragtx
- VKoskiv
- voidmain
- wbsmolen
- xinxi

And to those that reported security issues:

- beardnboobies
