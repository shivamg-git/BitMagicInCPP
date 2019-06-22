Binary representation of a even number has no set bit at right most or LSB postion but odd number does so we can check like
   if x & 1
      fmt.Println("ODD")
   else
      fmt.Println("EVEN")