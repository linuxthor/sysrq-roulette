sysrq-roulette
==============

Adds a SysRq handler with random kernel panic. Do you feel lucky?

Created as many systems no longer have a /dev/kmem so 'kmem Russian 
roulette' isn't possible.

Build kernel module with 'make' then insmod ./sysrq.ko 

Play with:

echo a > /proc/sysrq-trigger

The game is over when the kernel panics.. 
