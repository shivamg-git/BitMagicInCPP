We as programmers write below code block a lot times (literally a lot!)
   if (x == a)
      x = b;
   if (x == b)
      x = a;
Better way

   x = a ^ b ^ x 