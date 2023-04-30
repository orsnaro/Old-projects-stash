<?php $user_name = "username" ?>
<?php
echo $_SERVER["HTTP_CONNECTION"];
?>
<?php
echo $_REQUEST[];
?>

<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>
		<?php echo $user_name ?> WEBSITE
	</title>
</head>

<body>
	<form action="" method="post">
		<P>
			<label for="username">focus on username</label>
			<input type="message" name="username" value="none">
			< </P>
				<p>
					<?php
					echo $_POST[$user_name];
					?>
				</p>
				<P>
					<label for="password">focus on password</label>
					<input type="PASSWORD" placeholder="pass" name="pass">
					< </P>
						<p>
							<?php echo $_POST['pass']; ?>
						</p>

						<DIVE>
							<label for="send">focus on send buttion </label>
							<input type="submit" name="send">
						</DIVE>
	</form>
</body>

</html>