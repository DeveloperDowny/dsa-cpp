class LRU():
    def __init__(self):
        self.bank = []
        self.maxSize = 3
    
    def tryFetching(self, data):
        for (i, v) in enumerate(self.bank):
            if v == data:
                self.bank.remove(data)
                self.bank.insert(0, data)
                
                print(f"Cache Hit For {data}")
                return
        
        if len(self.bank) < self.maxSize:
            self.bank.insert(0,data)
            print(f"Cache Miss\nAdding {data} to Cache Memory")
        elif len(self.bank) >= self.maxSize:
            self.bank.insert(0, data)
            print(f"Overflow\nReplacing {self.bank.pop()} with {data}")

testArr = [1,2,3,1,4]
sol = LRU()
for i in testArr:
    sol.tryFetching(i)
    print()
        
        