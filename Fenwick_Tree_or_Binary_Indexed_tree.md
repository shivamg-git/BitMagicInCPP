Helps in calculating prefix sums in an array efficiently. For example, an array is [100, -100, -1, 1, 12] the length 3 prefix [100, -100, -1] with sum 100 - 100 + -1 = -1). If you are into competitve programming or have given long contest on codechef then 4/5 th question generally requires you to do things like

Point update operation : Update the value stored at an index i.
Range sum query : Find the sum of a prefix of length k.
Similar Data structure called Segment Trees also can be used to do things above mentioned but Fenwick tree code is much short, easier to understand and memory efficient on other side in a segment tree solution there exists a lot of boilerplate code. Also both DS take O(logN) time.
Prerequisite for fenwick trees : How to get last set bit ? For example For 1010, you should perform some operations to give 0010 as the output where 1 is last set bit in 1010. For this solution is just this simple equation x ^ (x & (x - 1)) (See how sharp bitwise solutions are!)..Lets make truth table of this to get how this equation works:

x(8)	x-1(7)	x & x-1 = mans	x ^ mans
1	1	1	0
1	0	0	1 last set bit
0	1	0	0
0	1	0	0
(x & (x - 1)) this equation actually came from our observation defined in above section. XOR(^) helps in removing 1 which exists in both results so we get last set bit!

We can use above equation and fenwick tree to maintain a partial sum tree(array to be precise). Denote BIT[] as fenwick tree and any index we can store sum of some numbers of any given array.

For every index i in the BIT[] array we store the cumulative sum from the index i to i - (1<<r) + 1 (both inclusive), where r represents the last set bit in the index i. So in mathematical equation this means

            {   
                a[1] + ... + a[x],     if x is power of 2
BIT[x] =                
                a[x],                  if x is odd
            }
How (x & (x - 1)) equation played a role in above fenwick equation?

If we see numbers 2,4,8.. in binary form 0010,0100,1000..so on then we always get a last set bit with no other set bits(1 bit) in the representation so if r represents set bit position ex: For 4 (0100) set bit position is 3(0 for 0 ,0 for 1, 1 for 2 if read from right -> left) so

if i = 4 then range [i to i - (1<<r) + 1] represents 4 to 4 - (2 r = 2 2 = 4) + 1 = [4,1] i.e index 4 should contain sum of first 4 elements.

if i = 16 then 16(10000)-(2 r = 2 4 = 16 - 16 + 1 = 1) i.e index 16 should contain sum of first 16 elements.

if i = 3 then 3(0011) - (2 r = 2 0 = 1 = 3-1+1) = [3,3] i.e index 3 will contain sum of only number at index 3 or just value at index 3.