//
//  main.swift
//  Produce_Swift
//
//  Created by ARCK on 08/02/2020.
//  Copyright © 2020 ARCK. All rights reserved.
//

import Foundation


var credit:Float=1
var fruit:[String] = ["Cherry","Bell","Lemon","Orange","Star","Skull"]


func roll() -> Void
{
    credit = credit - 0.2
    var results=[String]()
    var bell_num=0
    var skull_num=0
    var same_num=0
    
    for i in 0...2
    {
        let m=Int(arc4random() % 5)
        let k = fruit[m]
        results.append(k)
        if results[i] == "Skull"
        {
            skull_num += 1
        }
        if results[i] == "Bell"
        {
            bell_num += 1
        }
    }
    print("Results:",terminator:"")
    
    for i in results
    {
        print("\(i)",terminator:"  ")
    }
    
    print()
    
    if results[0] == results[1]
    {
            same_num += 1
    }
    if results[0] == results[2]
    {
            same_num += 1
    }
    if results[2] == results[1]
    {
            same_num += 1
    }

    if skull_num >= 2
    {
        if skull_num == 3
        {
                credit = 0
        }
        else if skull_num == 2
        {
                credit -= 1
        }
    }
    else if bell_num == 3
    {
            credit += 5
    }
    else if same_num == 3
    {
            credit += 1
    }
    else if same_num == 2
    {
            credit = credit + 0.5
    }
}

            
if credit < 0
{
    credit = 0
}
while credit >= 0.2
{
    let str = String(format: "%.1f", Float(credit))
    credit = Float(str) as! Float
        print("You have \(credit) credits")
        print("Would you like to continue or quiz?")
        let q = readLine()
        if q == "quiz"
        {
            break
    }
        roll()
}

print("In the end, you have \(credit) credits")
        





