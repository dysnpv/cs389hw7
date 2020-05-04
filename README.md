# CS389 HW7
author: Albert Ji

### Naive Impletation
It's worth mentioning that I modified the `driver.c` file, changing the time measuring method to `std::chrono::high_resolution_clock`. I did this because the c clock() function can't produce a precise measurement and will always return a 0s result for my naive version of `convert_all`. To accommodate this change, I changed the number of iters from 1000 to 3000.\
My naive version of `convert_all` would go through each charactor of the words, and by using the fact that `atoi(c) = c - '0'`, the function calculates the corresponding integers.\
The atoi version of `convert_all` used 25390ns, where my naive version only used 12995ns. 

### Optimization
The loop-to-if optimization.
   - We know that there are only 4 possible lengths for the words: 3, 4, 5 or 6. There are no words with less than 3 characters or more than 6 characters. We can take advantage of this point. Let `l = std::strlen(lines[i])`, then instead of looping from `line[i][0]` to `line[i][l]` and setting `nums[i] = nums[i] * 10 + lines[i][j] - '0'`, we can use statements like `if(l == 3) nums[i] = (lines[i][0] - '0') * 100 + (lines[i][1] - '0') * 10 + (lines[i][2] - '0');` to reduce the number of unnecessary times of writing to `nums[i]`.
   - Time used after this optimization: 8540ns.

The calculation optimization.
   - The if statements like `if(l == 3) nums[i] = (lines[i][0] - '0') * 100 + (lines[i][1] - '0') * 10 + (lines[i][2] - '0');` can be furtherly optimized by rearranging the calculation. Instead of calculation `lines[i][j] - '0'` each time, we can sum everything first and then minus `'0' * 111` in the end. The new if statement is `if(l == 3) nums[i] = lines[i][0] * 100 + lines[i][1] * 10 + lines[i][2] - '0' * 111`
   - Time used after this optimization: 8223ns.
   
The const variable optimization.
   - Maybe instead of using `0` in our calculation, using `const in ascii_zero = 48` would save us a little time? The if statement now is `if(l == 3) nums[i] = lines[i][0] * 100 + lines[i][1] * 10 + lines[i][2] - ascii_zero * 111`
   - Time used after this optimization: 8219ns. There is basically no improvement, which means this optimization has little effect.
   
A possible optimization that I didn't try: prefetching
   - One might think that we can prefetch the word `lines[i + 1]` while we are proccessing `lines[i]`. However, since `lines` is defined as a continuous array in `driver.c`, I don't think this optimization would work because modern cpu's prefetching optimization generally outperforms our manual optimization.
