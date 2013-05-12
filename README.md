# Arsino
Arsino is an Arduino program that implements pins server via serial port. You can manipulate digital and analog input and output.

## Making queries
* To get voltage on analog input send `a[PIN_NUMBER]e`.
* To get digital input send `d[PIN_NUMBER]e`.
* To set digital output send `D[PIN_NUMBER]e[VALUE]e`, where VALUE=0 is for LOW and other for HIGH.
* To set analog output send `A[PIN_NUMBER]e[VALUE]`, where VALUE should be in range of 0 to 255.
