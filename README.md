# CS389 HW7
author: Albert Ji

### Naive Impletation
It's worth mentioning that I modified the driver.c file, changing the time measuring method to `std::chrono::high_resolution_clock`. I did this because the c clock() function can't produce a precise measurement and will always return a 0s result for my naive version of `convert_all`.\
My naive version of `convert_all` would go through each charactor of the words, and by using the fact that `atoi(c) = c - '0'`, the function calculates the corresponding integers.\
The atoi version of `convert_all` used 25390ns, where my naive version only used 12995ns. 

### Optimization
1. The first optimization.
   - We know that there are only 4 possible lengths for the words: 3, 4, 5 or 6. There are no words with less than 3 characters or more than 6 characters. We can take advantage of this point. 
   - Time used: 8540ns.
