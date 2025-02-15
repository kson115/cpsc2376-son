#Identified Bugs and Fixes

##sumRange Function:
Bug 1: Off-by-One Error: for (int i = start; i < end; i++) { ... } iterates over the range from start to end - 1.   
Fix 1: Change (;i < end;) to for (;i <= end;).
 
##containsNegative Function:  
Bug 1: for loop condition, 'i <= numbers.size()', iterates one step too far, resulting in out-of-bounds access. 
Fix 1: To prevent out-of-bounds access, the correct condition should be 'i < numbers.size()'. 

Bug 2: comparison, 'numbers[i] > 0', checks for positive numbers instead of negative numbers.
Fix 2: To correctly check for negative numbers,it should be 'numbers[i] < 0'. 

##findMax Function:
Bug 1: 'if (numbers.empty()) return 0'
Fix 1: It worked/passed, but it is better to use exception: 'throw std::invalid_argument (" The input vector is empty")'.  

Bug 2: ‘i <= numbers.size()’
Fix 2: It should be `i < numbers.size()'.

Bug 3: `numbers[i] >= maxVal' 
Fix 3: It worked/passed, but it is better to use `numbers[i] > maxVal` to avoid update the unnecessary updates when numbers[i]==maxVal.  


