# SPFA_cpp_for_python

An example:

```python
import SPFA
import random as rd

rd.seed(1)
edges1 = [(20 * b + a, 20 * b + a + 23, rd.randint(0, 9)/10.0) for b in range(39) for a in range(20)]
edges2 = [(20 * b + a, 20 * b + a + 21, rd.randint(0, 9)/10.0) for b in range(39) for a in range(20)]
edges3 = [(20 * b + a, 20 * b + a + 20, rd.randint(0, 9)/10.0) for b in range(39) for a in range(20)]
edges4 = [(a, 800, rd.randint(0, 9)/10.0) for a in range(780, 800)]
edges5 = [(801, a, rd.randint(0, 9)/10.0) for a in range(20)]
edges = edges1 + edges2 + edges3 + edges4 + edges5

def cpp():
    x = SPFA.SPFA_instance(802)
    for edge in edges:
        x.InputAdjMat(edge[0], edge[1], edge[2])
    x.SetSourceAndTank(801,800)
    x.Solve()
    result = x.GetDistance()
    del x
    return result
    
cpp()
```

Output:
```
4.599999999999999
```
