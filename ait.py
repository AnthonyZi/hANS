from pyaitest import *
import time

def test():
 hh1 = np.dot(w_1,inn)
 hh1 = np.append(hh1,1)
 hh2 = np.dot(w_2,hh1)
 hh2 = np.append(hh2,1)
 hh3 = np.dot(w_3,hh2)
 hh3 = np.append(hh3, 1)
 hh4 = np.dot(w_4,hh3)
 hh4 = np.append(hh4,1)
 hh5 = np.dot(w_5, hh4)
 hh5 = np.append(hh5, 1)
 hh6 = np.dot(w_6, hh5)
 hh6 = np.append(hh6, 1)
 hh7 = np.dot(w_7,hh6)

def testt(times):
 start = time.time()
 for i in range(0,times):
  test();
 end = time.time()
 elapsed = end-start;
 print elapsed
