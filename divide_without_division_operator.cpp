 #include <bits/stdc++.h>
 using namespace std;
 
 int divide(long long dividend, long long divisor) {
 
   int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
   int quotient = 0;
 
   dividend = abs(dividend);
   divisor = abs(divisor);
 
   /* 1000/3 = 3 * (2^8 + 2^6 + 2^3 + 2^2 + 2^0) */
   for (int i = 31; i >= 0; --i) {
      if ((divisor << i) <= dividend) {
       dividend -= divisor << i;
       quotient += 1 << i;
     }
   }
   return (sign * quotient);
 }
 
 int main() {
   int a = 1000, b = 3;
   cout << divide(a, b) << "\n";
 
   a = 43, b = -8;
   cout << divide(a, b);
 
   return 0;
 }
