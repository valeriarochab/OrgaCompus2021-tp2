cd ./tests

echo "Test help command:"
../tp2 -h
echo " "

echo "Test version command:"
../tp2 -V
echo " "

echo "Test 1: 4 ways, 4KB cache, 32B blockSize: "
../tp2 -w 4 -c 4 -b 32 prueba1.mem

echo "Test 2: 4 ways, 4KB cache, 32B blockSize: "
../tp2 -w 4 -c 4 -b 32 prueba2.mem

echo "Test 3: 4 ways, 4KB cache, 32B blockSize: "
../tp2 -w 4 -c 4 -b 32 prueba3.mem

echo "Test 4: 4 ways, 4KB cache, 32B blockSize: "
../tp2 -w 4 -c 4 -b 32 prueba4.mem

echo "Test 5: 4 ways, 4KB cache, 32B blockSize: "
../tp2 -w 4 -c 4 -b 32 prueba5.mem

echo "Test 6: 1 way, 16KB cache, 128B blockSize: "
../tp2 -w 1 -c 16 -b 128 prueba1.mem

echo "Test 7: 1 way, 16KB cache, 128B blockSize: "
../tp2 -w 1 -c 16 -b 128 prueba2.mem

echo "Test 8: 1 way, 16KB cache, 128B blockSize: "
../tp2 -w 1 -c 16 -b 128 prueba3.mem

echo "Test 9: 1 way, 16KB cache, 128B blockSize: "
../tp2 -w 1 -c 16 -b 128 prueba4.mem

echo "Test 10: 1 way, 16KB cache, 128B blockSize: "
../tp2 -w 1 -c 16 -b 128 prueba5.mem