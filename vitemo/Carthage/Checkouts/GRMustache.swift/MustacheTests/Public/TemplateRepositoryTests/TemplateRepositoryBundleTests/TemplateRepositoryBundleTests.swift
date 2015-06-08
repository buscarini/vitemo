// The MIT License
//
// Copyright (c) 2015 Gwendal Roué
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


import XCTest
import Mustache

class TemplateRepositoryBundleTests: XCTestCase {
    
    func testTemplateRepositoryWithBundle() {
        let repo = TemplateRepository(bundle: NSBundle(forClass: self.dynamicType))
        
        var error: NSError?
        var template = repo.template(named: "notFound", error: &error)
        XCTAssertNil(template)
        XCTAssertNotNil(error)
        
        template = repo.template(named: "TemplateRepositoryBundleTests")
        var rendering = template?.render()
        XCTAssertEqual(rendering!, "TemplateRepositoryBundleTests.mustache TemplateRepositoryBundleTests_partial.mustache")
        
        template = repo.template(string: "{{>TemplateRepositoryBundleTests}}")
        rendering = template?.render()
        XCTAssertEqual(rendering!, "TemplateRepositoryBundleTests.mustache TemplateRepositoryBundleTests_partial.mustache")
        
        template = repo.template(string: "{{>TemplateRepositoryBundleTestsResources/partial}}")
        rendering = template?.render()
        XCTAssertEqual(rendering!, "partial sibling TemplateRepositoryBundleTests.mustache TemplateRepositoryBundleTests_partial.mustache")
    }
    
    func testTemplateRepositoryWithBundleTemplateExtensionEncoding() {
        var error: NSError?
        
        var repo = TemplateRepository(bundle: NSBundle(forClass: self.dynamicType), templateExtension: "text", encoding: NSUTF8StringEncoding)
        
        var template = repo.template(named: "notFound", error: &error)
        XCTAssertNil(template)
        XCTAssertNotNil(error)
        
        template = repo.template(named: "TemplateRepositoryBundleTests")
        var rendering = template?.render()
        XCTAssertEqual(rendering!, "TemplateRepositoryBundleTests.text TemplateRepositoryBundleTests_partial.text")
        
        template = repo.template(string: "{{>TemplateRepositoryBundleTests}}")
        rendering = template?.render()
        XCTAssertEqual(rendering!, "TemplateRepositoryBundleTests.text TemplateRepositoryBundleTests_partial.text")
        
        repo = TemplateRepository(bundle: NSBundle(forClass: self.dynamicType), templateExtension: "", encoding: NSUTF8StringEncoding)
        
        template = repo.template(named: "notFound", error: &error)
        XCTAssertNil(template)
        XCTAssertNotNil(error)
        
        template = repo.template(named: "TemplateRepositoryBundleTests")
        rendering = template?.render()
        XCTAssertEqual(rendering!, "TemplateRepositoryBundleTests TemplateRepositoryBundleTests_partial")
        
        template = repo.template(string: "{{>TemplateRepositoryBundleTests}}")
        rendering = template?.render()
        XCTAssertEqual(rendering!, "TemplateRepositoryBundleTests TemplateRepositoryBundleTests_partial")
    }
}
