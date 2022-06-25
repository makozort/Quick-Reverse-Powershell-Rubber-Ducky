
if (!$(Get-NetFirewallRule -DisplayName "rs1in" 2>$null)) {
	New-NetFirewallRule -DisplayName "rs1in" -Direction Inbound -LocalPort 1337 -Protocol TCP -Action Allow
} else {
	Write-Output "Rule already exists";
}

if (!$(Get-NetFirewallRule -DisplayName "rs1out" 2>$null)) {
	New-NetFirewallRule -DisplayName "rs1out" -Direction Outbound -LocalPort 1337 -Protocol TCP -Action Allow
} else {
	Write-Output "Rule already exists";
}

Try { 	
	$enc = [system.Text.Encoding]::UTF8
	# Set up endpoint and start listening	
	$endpoint = new-object System.Net.IPEndPoint([ipaddress]::any, 1337) 
	$server = new-object System.Net.Sockets.TcpListener $endpoint
	Write-Output "Booting server...";
	$server.Start();
	
	# Wait for an incoming connection 
	Write-Output "Waiting for client...";
	$client = $server.AcceptTcpClient() 
	Write-Output "Client Connected...";
	# Stream setup
	$stream = $client.GetStream() 
	$writer = New-Object System.IO.StreamWriter($stream)
	$out_str = "HELLO BACK HACKS!";
	$out_bytes = $enc.GetBytes($out_str);
	$writer.WriteLine($out_str);
	$writer.Flush();
 
	# Close TCP connection and stop listening
	$stream.Dispose();
	#$client.Close();
	$server.Stop();
	
}
Catch {
	Write-Output "Receive Message failed with: `n" + $Error[0];
}