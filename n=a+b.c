   // EE231002 Lab04. Solving Integer Equations
   // 109061145, 張智鈞
   // Date: 2020/10/19
  
  #include <stdio.h>
  
   int main(void)                            // execution start
   {
       long n;                               // Number n
      long a;                               // Number a
      long b;                               // Number b
      int Amax;                             // a max in loop
      int find = 0;                         // whether we found a group
      int total = 0;                        // count how many groups
 
      for (n = 2; n <= 5000; n++) {         // number n <= 5000
          find = 0;                         // reset find
          b = 1;                            // reset b
          while ( b * b < n * n * n) 
          b++;                              // count b max
          Amax = b;                         // give Amax
 
          for (a = 1; a < Amax ; a++) {
                                   // a is less than max and group not found
 
              while (a * a + b * b - n * n * n > 0 && b > 1) 
              b--;
                                   // decrease b until the gap = 0 or < 0
 
              if (a * a + b * b == n * n * n) {    // we found a group
                                          // find is true
                  total++;  
                                        // total found add 1
 
                  printf("%d: %d ^ 3 = %d ^ 2 + %d ^ 2\n",total,n,a,b);
                  break; 
                                                   // print the group
              }
          }
     }
      printf("%d solutions found for n <= 5000. \n", total);
                                       // print the final resut of groups
      return 0;                        // end of execution
  }