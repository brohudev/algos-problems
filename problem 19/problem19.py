class solution:
     def lastRemaining(self, n:int) -> int:
          return 1 if n==1 else 2*(n//2+1-self.lastRemaining(n//2))
    
s=solution()
 
print(s.lastRemaining(int(input())))
