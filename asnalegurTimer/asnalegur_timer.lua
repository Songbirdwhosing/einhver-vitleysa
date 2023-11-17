require('additional')


os.execute('clear')
function sleep(n)
	local i = 0
	while i <= n do 
		print(n-i .. ' seconds left')
		os.execute('sleep 1s')
		os.execute('clear')
		i = i+1
	end
end

sleep(60*2)
