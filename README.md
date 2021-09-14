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

## Binary search
```
while left <= right:
  mid = (left + right) // 2
  if A[mid] < target:
      left = mid+1
  elif A[mid] == target:
      // DO
  else:
      right = mid - 1
```

## Backtrack
```
def backtrack(tmp, to_iterate):
  if len(to_iterate) == 0:
      return 
  for it in to_iterate:
    tmp.add(it)
    backtrack(tmp, to_iterate)
    tmp.remove(it)
  return
```

## DP & DFS
```
def dfs(dp, currentCase):
  if currentCase == endCase:
    return 
  if not dp[currentCase]:
    dp[currentCase] = 'inf'
    for subCase in currentCase.getSubCases():
      dp[currentCase] = min(dp[currentCase], dfs(dp, subCase))
  return dp[currentCase]
```

## Trie/N-ary
```
class TrieNode:
  def __init__(self):
    self.children = {}
    self.end = False
```

## Dijikstra
```
graph = [[float('inf') for _ in cols] for _ in rows]
q = [(cost, init_x, init_y)]
while q:
  cost, x, y = q.pop(0)
  if (x,y) == target:
    return cost
  directions = [...]
  for (x_next, y_next) in directions:
    cost_next = cost + func(x_next, y_next)
    if cost_next < graph[x_next][y_next]:
      graph[x_next][y_next] = cost_next
      q.push(cost_next, x_next, y_next)
return graph[target]
```
