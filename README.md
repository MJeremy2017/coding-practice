# Coding Practice
---
## Digit Split
```
nums = 123
digits = []
while nums > 0:
  digit = nums % 10
  digits.append(digit)
  nums = nums // 10
```

## Knapsack
```
i: the current index so far
j: weight

dp[i][j]: the value can reached given limitation __j__ until item i, where not all __i__ items need to be selected.
------------------------------------------------------------------------------------------------------------------
if j-weights[i] < 0:
  dp[i][j] = dp[i-1][j]
dp[i][j] = max(dp[i-1][j], values[i] + dp[i-1][j-weights[i]])
  
```
