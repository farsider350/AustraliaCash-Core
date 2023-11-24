#!/usr/bin/env bash

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

AUSTRALIACASHD=${AUSTRALIACASHD:-$BINDIR/australiacashd}
AUSTRALIACASHCLI=${AUSTRALIACASHCLI:-$BINDIR/australiacash-cli}
AUSTRALIACASHTX=${AUSTRALIACASHTX:-$BINDIR/australiacash-tx}
AUSTRALIACASHQT=${AUSTRALIACASHQT:-$BINDIR/qt/australiacash-qt}

[ ! -x $AUSTRALIACASHD ] && echo "$AUSTRALIACASHD not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
AUSVER=($($AUSTRALIACASHCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for australiacashd if --version-string is not set,
# but has different outcomes for australiacash-qt and australiacash-cli.
echo "[COPYRIGHT]" > footer.h2m
$AUSTRALIACASHD --version | sed -n '1!p' >> footer.h2m

for cmd in $AUSTRALIACASHD $AUSTRALIACASHCLI $AUSTRALIACASHTX $AUSTRALIACASHQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${AUSVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${AUSVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
