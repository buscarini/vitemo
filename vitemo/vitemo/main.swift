//
//  main.swift
//  vitemo
//
//  Created by Jose Manuel Sánchez Peñarroja on 8/6/15.
//  Copyright (c) 2015 jms. All rights reserved.
//

import Foundation
import Result
import SwiftCLI

CLI.setup(name: "vitemo", version: "1.0", description: "Vitemo - VIPER template modules")
CLI.registerChainableCommand(commandName: "init")
	.withExecutionBlock {(arguments, options) in
		println("Initialize")
		return success()
}
CLI.registerChainableCommand(commandName: "new")
	.withExecutionBlock {(arguments, options) in
		println("Create template")
		return success()
}
CLI.registerChainableCommand(commandName: "list")
	.withExecutionBlock {(arguments, options) in
		println("List available template")
		return success()
}
CLI.go()
