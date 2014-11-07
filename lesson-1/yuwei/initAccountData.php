<?php

//注意：（根据需求需要修改的地方）
//1.数据库信息（function connectDataBase）
//2.表信息（function getAccountTableSql）
//3.insert的账号信息（function getAccountSql）

	$mysqli=new mysqli();

	//连接数据库 
	connectDataBase($mysqli);

	//创建关于accont的表
	createTable($mysqli);

	//通过检测表里面有没有信息，检测是否已经在表里面写入Accounts数据
	$hasCreateAccounts = hasInfoInTable($mysqli);
	
	if($hasCreateAccounts == false){
		createAccounts($mysqli);
	}

	$mysqli->close();
	echo "no bug";

//底下这段代码是copy过来的，注释很脏
function connectDataBase($mysqli){

	//设置数据库变量 
	$db_host   = 'localhost';  //数据库主机名称，一般都为localhost 
	$db_user   = 'root';        //数据库用户帐号，根据个人情况而定 
	$db_psw = '';   //数据库用户密码，根据个人情况而定 
	$db_name  = 'wordpress';         //数据库具体名称，以刚才创建的数据库为准 
	$mysqli->connect($db_host,$db_user,$db_psw,$db_name);

	//设置字符集，如utf8和gbk等，根据数据库的字符集而定 
	$mysqli->query("set names 'utf8'"); 

}

function createTable($mysqli){
	$createAccountTableSql = getAccountTableSql();
	$mysqli->query($createAccountTableSql);
}

function getAccountTableSql(){
	$createAccountTableSql = "CREATE TABLE account_list(
		id int,
		account varchar(255),
		password varchar(255),

		info_user varchar(10000),

		info_buy varchar(255),
		date_buy varchar(10),

		info_repair varchar(255),
		person_repair varchar(10),
		date_repair varchar(10)

		)CHARSET = utf8";

	return $createAccountTableSql;
}

function hasInfoInTable($mysqli){
	$firstAccountRowId = getFirstAccountRowId($mysqli);
	if($firstAccountRowId == 100){
		return true;
	}
	else{
		return false;
	}
}

function getFirstAccountRowId($mysqli){
	$getFirstAccountRowSql = "SELECT * FROM account_list
		WHERE account = '80000800'";
    $result = $mysqli->query($getFirstAccountRowSql);
	$firstAccountRow = $result->fetch_assoc();
	$id = $firstAccountRow['id'];
	return $id;
}

function createAccounts($mysqli){
	for ($i = 0; $i <= 1000; $i++) { 
		$initAccountsSql = getAccountsSql($i);

		$mysqli->query($initAccountSql);
	}
	echo "createAccounts ";
}

function getAccountsSql($i){
	$account = createAccount($i);
	$password = createPassword($i);
	$accountSql = "INSERT INTO account_list
	(id, account, password, info_user, info_buy, date_buy, info_repair, person_repair, date_repair)
	VALUES(".$i.",".$account.",".$password.",'','','','','','')";

	return $accountSql;
}

function createAccount($i){
	$account = 80000000;
	$account += $i*8;

	return $account;
}

function createPassword($i){
	$password = 123456789;
	for ($j = 0; $j <= $i; $j++) { 
		$password += $i*$j;
	}

	return $password;
}

?>