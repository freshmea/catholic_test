
class Test:

  def __init__(self):
    self.var = 10
    self.var2 = 20

  def aa(self):
    print('aaaabb')




class Inh(Test):

  def __init__(self):
    super().__init__()



def main():
  a = 10
  a = 'hellow'
  b = int()
  print(a)
  ob =Test()
  ob2 = Test()
  inob = Inh()
  ob.aa()
  ob.aa()
  print(ob.var)
  print(ob.var2)
  print(ob2.var)
  print(ob2.var2)
  inob.aa()



if __name__ == "__main__":
  main()



