import random

class dumpfile():
    def __init__(self,filename, attrib):
        #self.file = open('dump','w')
        self.file = open(filename,attrib)
        self.contan = {} 

    def writeRangeData(self):
        for i in range(10000):
            self.file.write(str(random.randint(1000000,10000000)))
            self.file.write("\n")

    def writeRandomData(self):
        for i in range(9000):
            self.file.write(str(random.randint(0,9000)))
            self.file.write("\n")

    def saveData(self):
        for line in self.file:
            num = line.strip()
            self.contan[num] = 0
    
    def checkData(self):
        self.file.seek(0)
        for line in self.file:
            num = line.strip()
            if(self.contan[num] == 1):
                print "%s already contain!" %num
            self.contan[num] = 1
            #print "number is %d." %self.contan[num]

    def dataLen(self):
        print len(list(self.contan))


cfile = dumpfile('random','w')
cfile.writeRandomData()
