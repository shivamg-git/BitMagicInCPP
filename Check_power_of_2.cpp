All the power of 2 have only single bit set and using our x and x-1 observation 
if we perform (x & x-1) then if x is power of 2 this will give 0 otherwise 1. 
So !(x & x-1) will give whether the number is power of 2. If case of x = 0 
we dont wish to do x-1 so final equation is

(x && !(x & x-1))