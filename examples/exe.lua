
--
-- exe.lua 
-- Written by Ena on the 13th November '21 at 6:20PM Australian Western Standard Time
--
-- @note: The only difference between the two is that,
-- the for loop in Lua counts up while exe.bin counts down.
-- This does not affect the final result which is, r1 = 4416
--

local r10 = 1 
local r2  = 6
local r1  = 69

for i=1, r2, 1 do
    r1 = r1 + r1
end

-- below is not apart of the actual code of exe.bin but is self explanatory.
print(r1)
print(r2)