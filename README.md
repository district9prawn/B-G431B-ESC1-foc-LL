# B-G431B-ESC1-foc-LL
Field-oriented control firmware for B-G431B-ESC1
Uses CORDIC co-processor for trigonometric calculations.
Started a bit of work on square wave HFI. Not silent due to current sampling limitation with low side shunts. 
One phase guarded by the analog watchdog. AWD errata will make guarding all channels a bit annoying!