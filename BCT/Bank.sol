// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;
// 3. Write a smart contract on a test network, for Bank account of a customer for following
// operations:
//  Deposit money
//  Withdraw Money
//  Show balance

// Declare the contract called Bank
contract Bank {
    // Mapping to store the balance of each user's account
    mapping(address => uint256) private balances;// om - 10

    // Event to log deposits
    event Deposited(address indexed accountHolder, uint256 amount);
    
    // Event to log withdrawals
    event Withdrawn(address indexed accountHolder, uint256 amount);

    // Function to deposit Ether into the user's account
    function deposit() public payable {
        balances[msg.sender] += msg.value;  // Increment user's balance with deposited Ether
        emit Deposited(msg.sender, msg.value);
    }

    // Function to withdraw Ether from the user's account
    function withdraw(uint256 amount) public {
        require(amount <= balances[msg.sender], "Insufficient balance to withdraw");
        balances[msg.sender] -= amount;  // Deduct user's balance by the withdrawal amount
        payable(msg.sender).transfer(amount);  // Transfer Ether back to the user
        emit Withdrawn(msg.sender, amount);
    }

    // Function to get the current balance of the caller's account
    function getBalance() public view returns (uint256) {
        // Return the caller's balance
        return balances[msg.sender];
    }
}






    // Function to deposit money into the account
    // function deposit(uint256 amount) public {
    //     // Add the deposited amount to the balance
    //     balance += amount;

    //     // Emit the deposit event for logging
    //     emit Deposited(msg.sender, amount);
    // }

    // // Function to withdraw money from the account
    // function withdraw(uint256 amount) public {
    //     // Ensure that there is enough balance to withdraw the requested amount
    //     require(amount <= balance, "Insufficient balance to withdraw");

    //     // Subtract the withdrawal amount from the balance
    //     balance -= amount;

    //     // Emit the withdrawal event for logging
    //     emit Withdrawn(msg.sender, amount);
    // }
