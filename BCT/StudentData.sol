// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData {
    
    struct Student {
        uint id;
        string name;
        uint age;
    }

    // Array to store list of students
    Student[] public students;

    // Mapping to check if a student with a specific ID exists
    mapping(uint => bool) private studentExists;

    // Event to log student addition, update, and deletion
    event StudentAdded(uint id, string name, uint age);
    event StudentUpdated(uint id, string name, uint age);
    event StudentDeleted(uint id);

    // Function to add a new student (Create)
    function addStudent(uint _id, string memory _name, uint _age) public {
        require(!studentExists[_id], "Student with this ID already exists.");
        students.push(Student(_id, _name, _age));
        studentExists[_id] = true;
        emit StudentAdded(_id, _name, _age);
    }

    // Function to get student details by index (Read)
    function getStudent(uint index) public view returns (uint, string memory, uint) {
        require(index < students.length, "Student does not exist");
        Student memory student = students[index];
        return (student.id, student.name, student.age);
    }

    // Function to update student details by ID (Update)
    function updateStudent(uint _id, string memory _name, uint _age) public {
        require(studentExists[_id], "Student does not exist.");
        for (uint i = 0; i < students.length; i++) {
            if (students[i].id == _id) {
                students[i].name = _name;
                students[i].age = _age;
                emit StudentUpdated(_id, _name, _age);
                return;
            }
        }
    }

    // Function to delete a student by ID (Delete)
    function deleteStudent(uint _id) public {
        require(studentExists[_id], "Student does not exist.");
        
        // Find and remove student by shifting array elements
        for (uint i = 0; i < students.length; i++) {
            if (students[i].id == _id) {
                students[i] = students[students.length - 1];
                students.pop();
                studentExists[_id] = false;
                emit StudentDeleted(_id);
                return;
            }
        }
    }

    // Fallback function to handle ether sent to the contract
    // fallback() external payable {
    //     // This contract does not accept Ether, so we can just revert any transactions sent with Ether
    //     revert("This contract does not accept Ether.");
    // }

    // Function to get the contract's balance (for demonstration purposes)
    function getBalance() public view returns (uint) {
        return address(this).balance;
    }

    // Function to get the total number of students
    function getStudentCount() public view returns (uint) {
        return students.length;
    }
}
