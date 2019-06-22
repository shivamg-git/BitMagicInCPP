Using XOR we can do this for example :- Swapping i with k and viceversa.
    i = i ^ k; // i has both i and k let it be I
    k = i ^ k; // remove k from I so k = i
    i = i ^ k; // remove k (which is now i) from I so i = k