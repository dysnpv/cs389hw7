# CS389 HW7
author: Albert Ji

### Naive Impletation
It's worth mentioning that I modified the driver.c file, changing the time measuring method to `std::chrono::high_resolution_clock`. I did this because the c clock() function can't produce a precise measurement and will always return a 0s result for my naive version of `convert_all`.
My naive version of `convert_all` would go through each charactor of the words, and by using the fact that `atoi(c) = c - '0'`, the function calculates the corresponding integers.
The atoi version of `convert_all` used 25390ns, where my naive version only used 12995ns. 
