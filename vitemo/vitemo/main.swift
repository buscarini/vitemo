//
//  main.swift
//  vitemo
//
//  Created by Jose Manuel Sánchez Peñarroja on 8/6/15.
//  Copyright (c) 2015 jms. All rights reserved.
//

import Foundation
import Result
import OptionKit

println("Hello, World!")



let optTemplate = Option(trigger:.Mixed("t", "template"))

let parser = OptionParser(definitions:[optTemplate])
let actualArguments = Array(Process.arguments[1..<Process.arguments.count])
let result = parser.parse(actualArguments)

switch result {
case .Success(let box):
	let (options, rest) = box.unbox
	
	if (rest.count==0) {
		println("Usage: vitemo module_name [-t template_name]")
		exit(1)
	}
	
	let template = options[optTemplate]?.first ?? "default"
	
	
	
	
case .Failure(let err):
	println(err)
}