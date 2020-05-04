# CS389 HW7
author: Albert Ji

### Naive Impletation
It's worth mentioning that I modified the driver.c file, changing the time measuring method to `std::chrono::high_resolution_clock`. I did this because the c clock() function can't produce a precise measurement and will always return a 0s result for my naive version of `convert_all`. To accommodate this change, I changed the number of iters from 1000 to 3000.\
My naive version of `convert_all` would go through each charactor of the words, and by using the fact that `atoi(c) = c - '0'`, the function calculates the corresponding integers.\
The atoi version of `convert_all` used 25390ns, where my naive version only used 12995ns. 

### Optimization
1. The loop to if optimization.
   - We know that there are only 4 possible lengths for the words: 3, 4, 5 or 6. There are no words with less than 3 characters or more than 6 characters. We can take advantage of this point. Let `l = std::strlen(lines[i])`, then instead of looping from `line[i][0]` to `line[i][l]` and setting `nums[i] = nums[i] * 10 + lines[i][j] - '0'`, we can use statements like `if(l == 3) nums[i] = (lines[i][0] - '0') * 100 + (lines[i][1] - '0') * 10 + (lines[i][2] - '0');` to reduce the number of unnecessary times of writing to `nums[i]`.
   - Time used after this optimization: 8540ns.
